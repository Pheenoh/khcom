.syntax unified
	.align 2, 0
	.global func_080AAF20
	.thumb
	.thumb_func
	.type func_080AAF20, %function
func_080AAF20: @ 080AAF20
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _080AAF6C @ =0x000006EE
	adds r0, r4, r1
	movs r2, #0x00
	ldsh r1, [r0, r2]
	subs r1, #0x04
	movs r0, #0xA8
	lsls r0, r0, #0x07
	bl __divsi3
	movs r3, #0xD4
	lsls r3, r3, #0x03
	adds r2, r4, r3
	ldr r1, _080AAF70 @ =0x000006EC
	adds r4, r4, r1
	movs r3, #0x00
	ldsh r1, [r4, r3]
	subs r1, #0x04
	muls r0, r1
	movs r3, #0xA0
	lsls r3, r3, #0x06
	adds r0, r0, r3
	str r0, [r2, #0x00]
	movs r1, #0xF8
	lsls r1, r1, #0x07
	cmp r0, r1
	ble _080AAF5A
	str r1, [r2, #0x00]
_080AAF5A:
	ldr r1, [r2, #0x00]
	ldr r0, _080AAF74 @ =0x000027FF
	cmp r1, r0
	bgt _080AAF64
	str r3, [r2, #0x00]
_080AAF64:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080AAF6C: .4byte 0x000006EE
_080AAF70: .4byte 0x000006EC
_080AAF74: .4byte 0x000027FF
.syntax divided
