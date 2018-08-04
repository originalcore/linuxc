all:
	make -C lib/static
	make -C lib/dynamic
	make -C app
	cp app/testapp .

clean:
	rm lib/static/*.o
	rm lib/static/*.a
	rm lib/dynamic/*.o
	rm lib/dynamic/*.so
	rm app/*.o
	rm app/testapp
	rm testapp
