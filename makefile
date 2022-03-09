# File targets
kernel/kernel.img:
	(cd kernel && make all)

./build:
	mkdir build
	cp -r fs/* build/

os.iso: ./build kernel/kernel.img
	cp kernel/kernel.img build/boot/myos.bin
	grub-mkrescue -o os.iso build

# Named targets
kernel: kernel/kernel.img
all: os.iso

run: os.iso
	qemu-system-i386 -cdrom os.iso

clean:
	rm -rf os.iso build
	(cd kernel && make clean)