.syntax unified
	.text
	.align 2, 0
	.global task_bos_jf_0
	.thumb
	.thumb_func
	.type task_bos_jf_0, %function
task_bos_jf_0:
	.incbin "roms/B8CJ.gba", 0xbcf40, 0x348
.syntax divided
