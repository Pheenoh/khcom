.syntax unified
	.align 2, 0
	.global func_0810B4B4
	.thumb
	.thumb_func
	.type func_0810B4B4, %function
func_0810B4B4: @ 0810B4B4
	push {r4, r5, lr}
	adds r3, r0, #0x0
	ldrb r0, [r3, #0x00]
	cmp r0, #0x00
	beq _0810B4E6
	ldr r1, _0810B4EC @ =0x09A4CAC4
	movs r2, #0x02
	ldsh r0, [r3, r2]
	lsls r4, r0, #0x01
	adds r1, r4, r1
	movs r5, #0x04
	ldsh r2, [r3, r5]
	movs r5, #0x00
	ldsh r0, [r1, r5]
	cmp r2, r0
	ble _0810B4E0
	ldr r0, _0810B4F0 @ =0x09A4CABE
	adds r0, r4, r0
	ldrh r0, [r0, #0x00]
	movs r1, #0x00
	strh r0, [r3, #0x02]
	strh r1, [r3, #0x04]
_0810B4E0:
	ldrh r0, [r3, #0x04]
	adds r0, #0x01
	strh r0, [r3, #0x04]
_0810B4E6:
	pop {r4, r5}
	pop {r0}
	bx r0
_0810B4EC: .4byte 0x09A4CAC4
_0810B4F0: .4byte 0x09A4CABE
.syntax divided
