.syntax unified
	.align 2, 0
	.global task_btl_badstatus_2
	.thumb
	.thumb_func
	.type task_btl_badstatus_2, %function
task_btl_badstatus_2:
	.incbin "roms/B8CJ.gba", 0x40bc8, 0xa8
.syntax divided
