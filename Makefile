# Diretórios
KERNEL_DIR = code/kernel
GRUB_DIR = grub
KERNEL_DEST = $(GRUB_DIR)/bin/waresdes/kern

# Arquivos e nomes
KERNEL = kernel.elf
ISO = myos.iso
C_SOURCES = kernel.o i386.c gui/date_and_time.c gui/main.c gui/buttons.c gui/menu.c drivers/mouse.c gui/string.c  gui/install/main.c drivers/disk.c screen.c 
OBJS = $(addprefix $(KERNEL_DIR)/, $(C_SOURCES:.c=.o))

# Compiladores e flags
CC = gcc
LD = ld
CFLAGS = -m32 -Wall -ffreestanding -fno-pic
LDFLAGS = -m elf_i386 -T linker.ld

# Alvo padrão
all: force $(KERNEL) iso

# Força tudo
force:
	@echo "🔥 Forçando recompilação..."
	@rm -f $(OBJS) $(KERNEL)

# Compilar os .c
$(KERNEL_DIR)/%.o:
	$(CC) $(CFLAGS) -c $(KERNEL_DIR)/$*.c -o $@

# Linkar o kernel
$(KERNEL): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

# Criar ISO com GRUB
iso: $(KERNEL)
	mkdir -p $(KERNEL_DEST)
	cp $(KERNEL) $(KERNEL_DEST)/kernel.elf
	
	grub-mkrescue -o $(ISO) $(GRUB_DIR)
	@echo "💿 ISO criada com sucesso: $(ISO)"
	/usr/lib/virtualbox/VirtualBoxVM --comment "waresdes 1.0 com amdwa-spk" --startvm "{b01eb2e0-8747-433b-a595-071261c8ab5b}"

# Limpar tudo
clean:
	rm -f $(OBJS) $(KERNEL) $(ISO)
	rm -f $(KERNEL_DEST)/kernel.elf
	@echo "🧹 Limpeza feita!"
