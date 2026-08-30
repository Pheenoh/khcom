# Kingdom Hearts: Chain of Memories (GBA) decompilation
#
#   make            build the US ROM and verify it matches
#   make VERSION=jp build the JP ROM (also: eu)
#   make all_versions

VERSION ?= us

ROMCODE_us := B8CE
ROMCODE_jp := B8CJ
ROMCODE_eu := B8CP

SHA1_us := 10729bd884f8fdca7a310b6d606c52e46657aa48
SHA1_jp := 59ec0a0a4ccd1e6acb3bbd7bfb21d63988958cfa
SHA1_eu := 8db73586cdb11b3795907edebf43228dbcd3e6b2

ROMCODE  := $(ROMCODE_$(VERSION))
SHA1     := $(SHA1_$(VERSION))
BASEROM  := roms/$(ROMCODE).gba

BUILD    := build/$(VERSION)
NAME     := com_$(VERSION)
ELF      := $(BUILD)/$(NAME).elf
ROM      := $(BUILD)/$(NAME).gba
MAP      := $(BUILD)/$(NAME).map

PREFIX  ?= arm-none-eabi-
AS      := $(PREFIX)as
LD      := $(PREFIX)ld
OBJCOPY := $(PREFIX)objcopy

ASFLAGS := -mcpu=arm7tdmi -march=armv4t -mthumb-interwork -I include

ASM_SRCS := $(wildcard asm/$(VERSION)/*.s)
ASM_OBJS := $(patsubst asm/$(VERSION)/%.s,$(BUILD)/asm/%.o,$(ASM_SRCS))

.PHONY: all check clean all_versions
all: check

$(BUILD)/asm/%.o: asm/$(VERSION)/%.s $(BASEROM)
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

$(ELF): $(ASM_OBJS) linker/$(VERSION).ld
	$(LD) -T linker/$(VERSION).ld -Map $(MAP) -o $@ $(ASM_OBJS)

$(ROM): $(ELF)
	$(OBJCOPY) -O binary --pad-to 0xA000000 --gap-fill 0xFF $< $@
	@truncate -s 33554432 $@

check: $(ROM)
	@echo "$(SHA1)  $(ROM)" | sha1sum -c

$(BASEROM):
	$(error Missing base ROM $(BASEROM) — place it in roms/)

clean:
	rm -rf build

all_versions:
	$(MAKE) VERSION=us
	$(MAKE) VERSION=jp
	$(MAKE) VERSION=eu
