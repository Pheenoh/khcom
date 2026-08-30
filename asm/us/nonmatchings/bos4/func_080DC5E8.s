.syntax unified
	.align 2, 0
	.global func_080DC5E8
	.thumb
	.thumb_func
	.type func_080DC5E8, %function
func_080DC5E8: @ 080DC5E8
	push {r4, r5, lr}
	ldr r0, _080DC610 @ =0x02034F0C
	ldr r0, [r0, #0x00]
	adds r5, r0, #0x0
	adds r5, #0x50
	movs r1, #0x00
	ldsh r4, [r5, r1]
	adds r0, #0x52
	movs r2, #0x00
	ldsh r0, [r0, r2]
	movs r1, #0x03
	bl func_0811D5EC
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	lsls r0, r1, #0x01
	cmp r4, r0
	ble _080DC614
	movs r0, #0x00
	b _080DC622
_080DC610: .4byte 0x02034F0C
_080DC614:
	movs r2, #0x00
	ldsh r0, [r5, r2]
	cmp r0, r1
	bgt _080DC620
	movs r0, #0x02
	b _080DC622
_080DC620:
	movs r0, #0x01
_080DC622:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
