ver = 1.0.2
file = ../wemos-$(ver).tar.gz
gz:
	tar -zcvf $(file) --exclude ../wemos_boards/.git --exclude ../wemos_boards/json.py --exclude Makefile ../wemos_boards/
	./json.py $(file) $(ver)

clean:
	rm -rf $(file)