.syntax unified
	.text
	.align 2, 0
	.global eu_080DA80C
	.thumb
	.thumb_func
	.type eu_080DA80C, %function
eu_080DA80C:
	.incbin "roms/B8CP.gba", 0xda80c, 0x24
	.align 2, 0
	.global eu_080DA830
	.thumb
	.thumb_func
	.type eu_080DA830, %function
eu_080DA830:
	.incbin "roms/B8CP.gba", 0xda830, 0x18
	.align 2, 0
	.global eu_080DA848
	.thumb
	.thumb_func
	.type eu_080DA848, %function
eu_080DA848:
	.incbin "roms/B8CP.gba", 0xda848, 0x18
	.align 2, 0
	.global eu_080DA860
	.thumb
	.thumb_func
	.type eu_080DA860, %function
eu_080DA860:
	.incbin "roms/B8CP.gba", 0xda860, 0x14
.syntax divided
