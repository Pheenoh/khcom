.syntax unified
	.align 2, 0
	.global func_0800284C
	.thumb
	.thumb_func
	.type func_0800284C, %function
func_0800284C: @ 0800284C
	push {lr}
	adds r1, r0, #0x0
	ldrh r2, [r1, #0x04]
	movs r3, #0x04
	ldsh r0, [r1, r3]
	cmp r0, #0x00
	ble _08002860
	subs r0, r2, #0x1
	strh r0, [r1, #0x04]
	b _08002876
_08002860:
	movs r0, #0x00
	str r0, [r1, #0x2C]
	adds r0, r1, #0x0
	adds r0, #0x0C
	ldr r1, _0800287C @ =0x030074C8
	ldr r1, [r1, #0x00]
	movs r2, #0xC0
	lsls r2, r2, #0x05
	adds r1, r1, r2
	bl func_08000C54
_08002876:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800287C: .4byte 0x030074C8
.syntax divided
