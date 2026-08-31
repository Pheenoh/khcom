.syntax unified
	.align 2, 0
	.global task_poo_shadow_2
	.thumb
	.thumb_func
	.type task_poo_shadow_2, %function
task_poo_shadow_2:
	.incbin "roms/B8CJ.gba", 0xcc008, 0xc
.syntax divided
