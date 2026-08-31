.syntax unified
	.align 2, 0
	.global task_bos_boogie_disk_1
	.thumb
	.thumb_func
	.type task_bos_boogie_disk_1, %function
task_bos_boogie_disk_1:
	.incbin "roms/B8CJ.gba", 0xdae14, 0x198
.syntax divided
