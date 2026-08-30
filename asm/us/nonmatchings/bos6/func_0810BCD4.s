.syntax unified
	.align 2, 0
	.global func_0810BCD4
	.thumb
	.thumb_func
	.type func_0810BCD4, %function
func_0810BCD4: @ 0810BCD4
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r4, #0x0
	adds r5, #0x40
	ldr r1, [r4, #0x28]
	ldr r2, [r4, #0x2C]
	movs r0, #0x80
	lsls r0, r0, #0x02
	adds r2, r2, r0
	adds r0, r5, #0x0
	movs r3, #0x00
	bl func_08012324
	ldr r1, [r4, #0x30]
	negs r1, r1
	lsls r1, r1, #0x08
	lsrs r1, r1, #0x10
	adds r0, r5, #0x0
	bl func_08012658
	ldr r0, [r4, #0x30]
	cmp r0, #0x00
	ble _0810BD0C
	adds r0, r5, #0x0
	movs r1, #0x01
	bl func_08012614
	b _0810BD14
_0810BD0C:
	adds r0, r5, #0x0
	movs r1, #0x00
	bl func_08012614
_0810BD14:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
