.syntax unified
	.align 2, 0
	.global func_080E6968
	.thumb
	.thumb_func
	.type func_080E6968, %function
func_080E6968: @ 080E6968
	push {r4, lr}
	adds r4, r2, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_080E548C
	ldr r1, [r0, #0x0C]
	ldr r0, [r0, #0x08]
	subs r1, r1, r0
	lsls r1, r1, #0x08
	lsrs r1, r1, #0x10
	movs r0, #0x00
	lsls r4, r4, #0x04
	cmp r1, r4
	ble _080E6990
	movs r0, #0x01
_080E6990:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
