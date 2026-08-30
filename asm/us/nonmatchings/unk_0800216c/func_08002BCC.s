.syntax unified
	.align 2, 0
	.global func_08002BCC
	.thumb
	.thumb_func
	.type func_08002BCC, %function
func_08002BCC: @ 08002BCC
	push {r4, lr}
	adds r4, r0, #0x0
	ldrh r1, [r4, #0x04]
	movs r2, #0x04
	ldsh r0, [r4, r2]
	cmp r0, #0x00
	ble _08002BE0
	subs r0, r1, #0x1
	strh r0, [r4, #0x04]
	b _08002C00
_08002BE0:
	movs r0, #0x00
	str r0, [r4, #0x24]
	ldrh r0, [r4, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_08005C60
	adds r0, r4, #0x0
	adds r0, #0x0C
	ldr r1, _08002C08 @ =0x030074C8
	ldr r1, [r1, #0x00]
	ldr r2, _08002C0C @ =0x00001A94
	adds r1, r1, r2
	bl func_08000C54
_08002C00:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08002C08: .4byte 0x030074C8
_08002C0C: .4byte 0x00001A94
.syntax divided
