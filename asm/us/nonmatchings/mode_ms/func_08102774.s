.syntax unified
	.align 2, 0
	.global func_08102774
	.thumb
	.thumb_func
	.type func_08102774, %function
func_08102774: @ 08102774
	push {r4, r5, r6, lr}
	movs r1, #0x00
_08102778:
	movs r2, #0x00
	lsls r5, r1, #0x10
_0810277C:
	ldr r6, _081027B0 @ =0x0203C590
	ldrb r0, [r6, #0x06]
	lsls r4, r2, #0x10
	lsrs r2, r4, #0x10
	lsrs r1, r5, #0x10
	bl func_08102688
	movs r0, #0x80
	lsls r0, r0, #0x09
	adds r4, r4, r0
	lsrs r2, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0x03
	ble _0810277C
	adds r0, r5, r0
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x03
	ble _08102778
	ldrb r0, [r6, #0x06]
	bl func_08102728
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_081027B0: .4byte 0x0203C590
.syntax divided
