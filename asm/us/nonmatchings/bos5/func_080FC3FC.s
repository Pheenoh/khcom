.syntax unified
	.align 2, 0
	.global func_080FC3FC
	.thumb
	.thumb_func
	.type func_080FC3FC, %function
func_080FC3FC: @ 080FC3FC
	push {r4, r5, lr}
	adds r5, r0, #0x0
	movs r2, #0x00
_080FC402:
	lsls r2, r2, #0x10
	asrs r1, r2, #0x10
	lsls r0, r1, #0x04
	adds r0, r0, r1
	lsls r0, r0, #0x04
	adds r0, #0x68
	adds r3, r5, r0
	lsls r1, r1, #0x02
	adds r0, r5, #0x0
	adds r0, #0x10
	adds r1, r0, r1
	ldr r0, [r1, #0x00]
	adds r4, r2, #0x0
	cmp r0, #0x02
	bne _080FC430
	movs r2, #0x1A
	ldsh r0, [r5, r2]
	cmp r0, #0x00
	bne _080FC430
	str r0, [r1, #0x00]
	adds r0, r3, #0x0
	bl func_0801AF08
_080FC430:
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r4, r1
	lsrs r2, r0, #0x10
	cmp r0, #0x00
	ble _080FC402
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
