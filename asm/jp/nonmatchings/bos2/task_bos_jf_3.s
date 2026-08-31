.syntax unified
	.align 2, 0
	.global task_bos_jf_3
	.thumb
	.thumb_func
	.type task_bos_jf_3, %function
task_bos_jf_3:
	.incbin "roms/B8CJ.gba", 0xbd528, 0x384
.syntax divided
