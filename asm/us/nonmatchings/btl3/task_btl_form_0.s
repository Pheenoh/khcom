.syntax unified
	.align 2, 0
	.global task_btl_form_0
	.thumb
	.thumb_func
	.type task_btl_form_0, %function
task_btl_form_0: @ 0803FDFC
	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0x0
	ldr r7, _0803FE68 @ =0x02039B84
	ldr r5, [r7, #0x00]
	ldr r1, [r5, #0x68]
	ldr r2, [r5, #0x6C]
	ldr r3, _0803FE6C @ =0x02000000
	ldr r4, _0803FE70 @ =0x00000000
	orrs r1, r3
	str r1, [r5, #0x68]
	str r2, [r5, #0x6C]
	movs r2, #0x00
	strh r2, [r0, #0x20]
	str r6, [r0, #0x08]
	ldr r1, [r6, #0x04]
	ldr r1, [r1, #0x00]
	str r1, [r0, #0x0C]
	ldrh r1, [r1, #0x08]
	strh r1, [r0, #0x00]
	movs r1, #0x01
	strh r1, [r0, #0x10]
	strh r2, [r0, #0x02]
	strh r2, [r0, #0x04]
	strh r2, [r0, #0x22]
	movs r1, #0x64
	strh r1, [r0, #0x24]
	adds r1, #0xBC
	adds r5, r5, r1
	strh r2, [r5, #0x00]
	movs r3, #0x00
	movs r2, #0x00
	ldsh r0, [r6, r2]
	cmp r3, r0
	bge _0803FE62
	adds r5, r7, #0x0
	adds r4, r1, #0x0
_0803FE44:
	ldr r2, [r5, #0x00]
	adds r2, r2, r4
	ldr r1, [r6, #0x04]
	lsls r0, r3, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x00]
	ldrh r1, [r2, #0x00]
	adds r0, r0, r1
	strh r0, [r2, #0x00]
	adds r3, #0x01
	movs r2, #0x00
	ldsh r0, [r6, r2]
	cmp r3, r0
	blt _0803FE44
_0803FE62:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0803FE68: .4byte 0x02039B84
_0803FE6C: .4byte 0x02000000
_0803FE70: .4byte 0x00000000
.syntax divided
