.syntax unified
	.align 2, 0
	.global task_bos_jf_lamp_2
	.thumb
	.thumb_func
	.type task_bos_jf_lamp_2, %function
task_bos_jf_lamp_2:
	.incbin "roms/B8CJ.gba", 0xbe1cc, 0x134
.syntax divided
