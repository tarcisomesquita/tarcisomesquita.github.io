// Content script que roda toda vez que a página é carregada
(function() {
    'use strict';
    
    // Função para fazer log dos cookies
    function logCookies() {
        const cookies = document.cookie;
        
        if (cookies) {
            console.log('🍪 Cookies da página tarcisomesquita.github.io:');
            console.log(cookies);
            
            // Também faz log de cada cookie separadamente para melhor visualização
            const cookieArray = cookies.split(';').map(cookie => cookie.trim());
            cookieArray.forEach((cookie, index) => {
                if (cookie) {
                    const [name, value] = cookie.split('=');
                    console.log(`Cookie ${index + 1}: ${name} = ${value}`);
                }
            });
        } else {
            console.log('🍪 Nenhum cookie encontrado na página tarcisomesquita.github.io');
        }
    }
    
    // Executa imediatamente quando o script carrega
    logCookies();
    
    // Também monitora mudanças nos cookies (caso sejam definidos dinamicamente)
    let lastCookies = document.cookie;
    
    const observer = new MutationObserver(function() {
        if (document.cookie !== lastCookies) {
            console.log('🍪 Cookies atualizados:');
            logCookies();
            lastCookies = document.cookie;
        }
    });
    
    // Monitora mudanças no documento
    if (document.body) {
        observer.observe(document.body, {
            childList: true,
            subtree: true
        });
    } else {
        // Se o body ainda não existe, espera ele ser criado
        document.addEventListener('DOMContentLoaded', function() {
            observer.observe(document.body, {
                childList: true,
                subtree: true
            });
        });
    }
    
    // Log adicional quando a página termina de carregar
    window.addEventListener('load', function() {
        console.log('🍪 Página carregada completamente - Cookies finais:');
        logCookies();
    });
})();