.syntax unified
	.align 2, 0
	.global task_bos_boogie_disk_2
	.thumb
	.thumb_func
	.type task_bos_boogie_disk_2, %function
task_bos_boogie_disk_2:
	.incbin "roms/B8CJ.gba", 0xdafac, 0x94
.syntax divided
