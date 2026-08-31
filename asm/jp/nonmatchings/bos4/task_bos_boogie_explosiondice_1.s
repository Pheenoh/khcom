.syntax unified
	.align 2, 0
	.global task_bos_boogie_explosiondice_1
	.thumb
	.thumb_func
	.type task_bos_boogie_explosiondice_1, %function
task_bos_boogie_explosiondice_1:
	.incbin "roms/B8CJ.gba", 0xda618, 0x80
.syntax divided
