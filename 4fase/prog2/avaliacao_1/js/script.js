function calculaTotal(){
  let p = parseInt(document.getElementById('quantidade-p').value);
  let m = parseInt(document.getElementById('quantidade-m').value);
  let g = parseInt(document.getElementById('quantidade-g').value);
  let gg = parseInt(document.getElementById('quantidade-gg').value);

  let nome = document.getElementsByName('nome-camisa')[0].checked;
  let miniatura = document.getElementsByName('miniatura-camisa')[0].checked;
  let acabamento = document.getElementsByName('acabamento-camisa')[0].checked;

  let total = p*20 + m*20 + g*20 + gg*20;

  total += nome ? 3*p+3*m+3*g+3*gg : 0;
  total += miniatura ? 4*p+4*m+4*g+4*gg : 0;
  total += acabamento ? 5*p+5*m+5*g+5*gg : 0;

  console.log('Total: '+total)
  document.getElementById('total').innerHTML = 'R$ '+total+',00'
}

function valida(){
  let p = parseInt(document.getElementById('quantidade-p').value);
  let m = parseInt(document.getElementById('quantidade-m').value);
  let g = parseInt(document.getElementById('quantidade-g').value);
  let gg = parseInt(document.getElementById('quantidade-gg').value);

  let total = p + m + g + gg;

  if(!total){
    console.error('Nenhuma camisa selecionada!');
    alert('Selecione pelo menos uma camisa!');
  }
}

