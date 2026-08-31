.syntax unified
	.align 2, 0
	.global task_btl_shadow_3
	.thumb
	.thumb_func
	.type task_btl_shadow_3, %function
task_btl_shadow_3:
	.incbin "roms/B8CJ.gba", 0x2f650, 0x18
.syntax divided
