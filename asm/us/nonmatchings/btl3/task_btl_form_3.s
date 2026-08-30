.syntax unified
	.align 2, 0
	.global task_btl_form_3
	.thumb
	.thumb_func
	.type task_btl_form_3, %function
task_btl_form_3: @ 08040048
	ldr r0, _0804005C @ =0x02039B84
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	ldr r2, _08040060 @ =0xFDFFFFFF
	ands r0, r2
	str r0, [r3, #0x68]
	str r1, [r3, #0x6C]
	bx lr
	.byte 0x00, 0x00
_0804005C: .4byte 0x02039B84
_08040060: .4byte 0xFDFFFFFF
.syntax divided
