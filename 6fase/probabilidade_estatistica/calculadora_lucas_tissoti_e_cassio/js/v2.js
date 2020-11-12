function displayclean() {
	document.getElementById('display01').value = '';
	document.getElementById('display02').value = '';
	document.getElementById('display03').value = '';
	document.getElementById('display04').value = '';
	document.getElementById('display05').value = '';
}

function calc() {
	n = parseInt(document.getElementById('display01').value)
	p = parseFloat(document.getElementById('display02').value)
	x = parseInt(document.getElementById('display03').value)

	let result = combinacao(n, x) * Math.pow(p, x) * Math.pow(1 - p, n - x)

	document.getElementById('display04').value = result * 100 + '%'
}

function calcacm() {
	let minimo = document.getElementById('acm-minimo').checked

	if (minimo) {
		calc_acm_min()
	} else {
		calc_acm_max()
	}
}


function calc_acm_max() {
	n = parseInt(document.getElementById('display01').value)
	p = parseFloat(document.getElementById('display02').value)
	x = parseInt(document.getElementById('display03').value)

	let resultacm = 0

  for (let i = x; i >= 0; i--) {
    resultacm += combinacao(n, i) * Math.pow(p, i) * Math.pow(1 - p, n - i)
  }

	document.getElementById('display05').value = resultacm * 100 + '%'
}

function calc_acm_min() {
  n = parseInt(document.getElementById('display01').value)
  p = parseFloat(document.getElementById('display02').value)
  x = parseInt(document.getElementById('display03').value)

  let resultacm = 0

  for (let i = x; i <= n; i++) {
    resultacm += combinacao(n, i) * Math.pow(p, i) * Math.pow(1 - p, n - i)
  }

  document.getElementById('display05').value = resultacm * 100 + '%'
}


function fatorial(n) {
  let fat = 1

  for (let i = 1; i <= n; i++) {
    fat *= i
  }

  return fat
}

function combinacao(n, x) {
  return fatorial(n) / (fatorial(n-x) * fatorial(x))
}