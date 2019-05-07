plot.png: ondad.dat plot.py
	python plot.py

%.dat : a.out
	./a.out 

a.out: ejercicio29.cpp
	g++ ejercicio29.cpp

clean:
	rm -rf a.out temperatura.dat plot.png *~