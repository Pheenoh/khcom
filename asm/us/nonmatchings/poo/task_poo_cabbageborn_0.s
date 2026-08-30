.syntax unified
	.align 2, 0
	.global task_poo_cabbageborn_0
	.thumb
	.thumb_func
	.type task_poo_cabbageborn_0, %function
task_poo_cabbageborn_0: @ 080D1628
	push {r4, lr}
	adds r4, r0, #0x0
	movs r1, #0x20
	bl func_08000E64
	movs r1, #0x00
	strh r1, [r4, #0x14]
	strh r1, [r4, #0x16]
	ldr r0, _080D1648 @ =0x02034E34
	strh r1, [r0, #0x00]
	ldr r0, _080D164C @ =0x02034E36
	strh r1, [r0, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D1648: .4byte 0x02034E34
_080D164C: .4byte 0x02034E36
.syntax divided
