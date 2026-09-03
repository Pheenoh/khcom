.syntax unified
	.text
	.align 2, 0
	.global task_bos_tm_tbl_1
	.thumb
	.thumb_func
	.type task_bos_tm_tbl_1, %function
task_bos_tm_tbl_1:
	.incbin "roms/B8CJ.gba", 0xbccb4, 0x278
.syntax divided
