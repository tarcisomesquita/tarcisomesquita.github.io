console.log('AQUI');
let idPerfil = document.getElementById('idPerfil').textContent.replace(/^Você está logado como: (.*)$/, '$1');
let idPerfilGoogle = document.getElementById('idPerfilGoogle').textContent.replace(/^.*: ([^@]*)@.*$/, '$1');

<ul id="decorNavMenuPopup" aria-labelledby="decorNavMenuButton" class="decor-header-description">
<li class="decor-header-greeting" id="saudacao">Olá, TARCISO MESQUITA DE OLIVEIRA</li>
<li class="decor-header-profile" id="idPerfil">Você está logado como: Professor</li>
<li class="decor-header-profile-extra" id="idPerfilGoogle">E-mail Institucional (via Google): tarcisomesquita@prof.educacao.sp.gov.br</li>

https://sed.educacao.sp.gov.br/Funcional/Consulta/ConsultaFuncionalPessoal
<input type="text" class="form-control cpf" id="txtNrCpf" maxlength="14" size="14" value="27785856800" readonly="">
<input name="telefone" class="form-control" id="telefone" readonly="True" size="15" type="text" value="(19) 99296-9405">
<input type="hidden" id="hdnNrRg" value="30801342">
