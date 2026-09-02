.syntax unified
	.align 2, 0
	.global func_0805F5A4
	.thumb
	.thumb_func
	.type func_0805F5A4, %function
func_0805F5A4: @ 0805F5A4
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	ldr r0, [r5, #0x00]
	ldr r1, [r6, #0x00]
	bl func_0805F588
	adds r4, r0, #0x0
	cmp r4, #0x00
	ble _0805F5D0
	ldr r0, [r5, #0x00]
	lsls r0, r0, #0x08
	adds r1, r4, #0x0
	bl __divsi3
	str r0, [r5, #0x00]
	ldr r0, [r6, #0x00]
	lsls r0, r0, #0x08
	adds r1, r4, #0x0
	bl __divsi3
	str r0, [r6, #0x00]
_0805F5D0:
	adds r0, r4, #0x0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
