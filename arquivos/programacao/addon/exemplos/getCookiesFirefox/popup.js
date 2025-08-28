document.addEventListener('DOMContentLoaded', function() {
    const cookieList = document.getElementById('cookieList');
    const domainFilter = document.getElementById('domainFilter');
    const refreshBtn = document.getElementById('refreshBtn');
    
    // Carrega os cookies inicialmente
    loadCookies();
    
    // Atualiza ao clicar no botão
    refreshBtn.addEventListener('click', loadCookies);
    
    // Filtra ao digitar no campo
    domainFilter.addEventListener('input', loadCookies);
    
    function loadCookies() {
        const filterValue = domainFilter.value.toLowerCase();
        
        cookieList.innerHTML = '<div class="loading">Carregando cookies...</div>';
        
        chrome.cookies.getAll({}, function(cookies) {
            if (chrome.runtime.lastError) {
                cookieList.innerHTML = `
                    <div class="error">
                        Erro ao carregar cookies: ${chrome.runtime.lastError.message}
                    </div>
                `;
                return;
            }
            
            if (cookies.length === 0) {
                cookieList.innerHTML = '<div class="loading">Nenhum cookie encontrado.</div>';
                return;
            }
            
            // Filtra cookies se houver um filtro aplicado
            const filteredCookies = filterValue 
                ? cookies.filter(cookie => 
                    cookie.domain.toLowerCase().includes(filterValue) ||
                    cookie.name.toLowerCase().includes(filterValue))
                : cookies;
            
            // Ordena por domínio
            filteredCookies.sort((a, b) => a.domain.localeCompare(b.domain));
            
            // Exibe os cookies
            cookieList.innerHTML = '';
            
            if (filteredCookies.length === 0) {
                cookieList.innerHTML = '<div class="loading">Nenhum cookie encontrado com o filtro aplicado.</div>';
                return;
            }
            
            filteredCookies.forEach(cookie => {
                const cookieElement = document.createElement('div');
                cookieElement.className = 'cookie-item';
                cookieElement.innerHTML = `
                    <div class="cookie-domain">${cookie.domain}</div>
                    <div class="cookie-name">${cookie.name}</div>
                    <div class="cookie-value">${truncateValue(cookie.value, 100)}</div>
                `;
                
                // Mostra o valor completo ao clicar
                cookieElement.addEventListener('click', function() {
                    alert(`Cookie completo:\n\nDomínio: ${cookie.domain}\nNome: ${cookie.name}\nValor: ${cookie.value}\n\nExpira em: ${cookie.expirationDate ? new Date(cookie.expirationDate * 1000) : 'Sessão'}`);
                });
                
                cookieList.appendChild(cookieElement);
            });
        });
    }
    
    function truncateValue(value, maxLength) {
        return value.length > maxLength 
            ? value.substring(0, maxLength) + '...' 
            : value;
    }
});
