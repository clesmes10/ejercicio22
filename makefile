segundo.png: gragauss.py seg.txt
	python gragauss.py
seg.txt:
	./seguder > seg.txt
seguder: derivadados.cpp
	c++ derivadados.cpp -o seguder
