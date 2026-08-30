.syntax unified
	.align 2, 0
	.global task_btl_pause_0
	.thumb
	.thumb_func
	.type task_btl_pause_0, %function
task_btl_pause_0: @ 080301F8
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _0803023C @ =0x08B1E7F4
	movs r1, #0xC0
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _08030240 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	ldr r1, _08030244 @ =0x09EE115C
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x08]
	ldr r0, [r1, #0x04]
	str r0, [r4, #0x0C]
	movs r0, #0x00
	strb r0, [r4, #0x10]
	strh r0, [r4, #0x24]
	strh r0, [r4, #0x26]
	ldr r0, _08030248 @ =0x02039B84
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _0803024C @ =0x04000000
	ldr r3, _08030250 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	pop {r4}
	pop {r0}
	bx r0
_0803023C: .4byte 0x08B1E7F4
_08030240: .4byte 0x08F69BA4
_08030244: .4byte 0x09EE115C
_08030248: .4byte 0x02039B84
_0803024C: .4byte 0x04000000
_08030250: .4byte 0x00000000
.syntax divided
