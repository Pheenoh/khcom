.syntax unified
	.align 2, 0
	.global func_080C6EB0
	.thumb
	.thumb_func
	.type func_080C6EB0, %function
func_080C6EB0: @ 080C6EB0
	push {r4, r5, r6, r7, lr}
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	cmp r3, #0x00
	ble _080C6EDA
	lsls r7, r2, #0x11
	adds r5, r1, #0x0
	adds r4, r0, #0x0
	adds r6, r3, #0x0
_080C6EC6:
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	lsrs r2, r7, #0x10
	bl RequestDma3Copy
	adds r5, #0x40
	adds r4, #0x40
	subs r6, #0x01
	cmp r6, #0x00
	bne _080C6EC6
_080C6EDA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
