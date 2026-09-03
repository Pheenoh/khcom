.syntax unified
	.text
	.align 2, 0
	.global task_bos_tm_tbl_1
	.thumb
	.thumb_func
	.type task_bos_tm_tbl_1, %function
task_bos_tm_tbl_1:
	.incbin "roms/B8CP.gba", 0xb8f04, 0x278
.syntax divided
