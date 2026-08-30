.syntax unified
	.align 2, 0
	.global func_0800F368
	.thumb
	.thumb_func
	.type func_0800F368, %function
func_0800F368: @ 0800F368
	push {r4, r5, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	lsls r4, r1, #0x10
	lsrs r4, r4, #0x10
	adds r0, #0x40
	mov r1, sp
	movs r2, #0x00
	movs r3, #0x00
	bl func_0801C700
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0x0
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _0800F3B4
	ldr r1, [r5, #0x44]
	ldr r0, [sp, #0x000]
	cmp r1, r0
	ble _0800F3A6
	ldr r0, [r5, #0x74]
	ldr r1, [r5, #0x78]
	movs r2, #0x04
	movs r3, #0x00
	orrs r0, r2
	b _0800F3B0
_0800F3A6:
	ldr r0, [r5, #0x74]
	ldr r1, [r5, #0x78]
	movs r2, #0x05
	negs r2, r2
	ands r0, r2
_0800F3B0:
	str r0, [r5, #0x74]
	str r1, [r5, #0x78]
_0800F3B4:
	add sp, #0x004
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
