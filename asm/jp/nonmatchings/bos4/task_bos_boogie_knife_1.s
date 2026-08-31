.syntax unified
	.align 2, 0
	.global task_bos_boogie_knife_1
	.thumb
	.thumb_func
	.type task_bos_boogie_knife_1, %function
task_bos_boogie_knife_1:
	.incbin "roms/B8CJ.gba", 0xdb230, 0x104
.syntax divided
