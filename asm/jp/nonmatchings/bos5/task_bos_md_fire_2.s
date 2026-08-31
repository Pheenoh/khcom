.syntax unified
	.align 2, 0
	.global task_bos_md_fire_2
	.thumb
	.thumb_func
	.type task_bos_md_fire_2, %function
task_bos_md_fire_2:
	.incbin "roms/B8CJ.gba", 0xfd334, 0xdc
.syntax divided
