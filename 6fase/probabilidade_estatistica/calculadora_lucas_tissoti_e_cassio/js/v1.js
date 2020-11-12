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

	q = 1 - p
	n_x = n - x
	p_pow_x = Math.pow(p, x)
	q_pow_n_x = Math.pow(q, n_x)

	let n1 = n
	let nf = 1
	let x1 = x
	let xf = 1
	let n_x1 = n_x
	let n_xf = 1

	for (x=1; x<=n1; x++) {
		nf = nf * x
	}

	for (x=1; x<=x1; x++) {
		xf = xf * x
	}

	for (x=1; x<=n_x1; x++) {
		n_xf = n_xf * x
	}

	cnx = nf / (n_xf * xf)

	result = p_pow_x * q_pow_n_x * cnx

	document.getElementById('display04').value = result * 100 + '%'
}

function calcacm(){
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

	for (xcont = x; xcont >= 0; xcont--) {
		q = 1 - p
		n_x = n - xcont
		p_pow_x = Math.pow(p, xcont)
		q_pow_n_x = Math.pow(q, n_x)

		let n1 = n
		let nf = 1
		let x1 = xcont
		let xf = 1
		let n_x1 = n_x
		let n_xf = 1

		for (x=1; x <= n1; x++) {
			nf = nf * x
		}

		for (x=1; x <= x1; x++) {
			xf = xf * x
		}

		for (x=1; x <= n_x1; x++) {
			n_xf = n_xf * x
		}

		cnx = nf / (n_xf * xf)
		resultacm += (p_pow_x * q_pow_n_x * cnx)
	}
	
	document.getElementById('display05').value = resultacm * 100 + '%'
}

function calc_acm_min() {
  n = parseInt(document.getElementById('display01').value)
  p = parseFloat(document.getElementById('display02').value)
  x = parseInt(document.getElementById('display03').value)
  let minimo = document.getElementById('acm-minimo').checked

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