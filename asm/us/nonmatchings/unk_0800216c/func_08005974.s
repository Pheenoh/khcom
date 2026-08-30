.syntax unified
	.align 2, 0
	.global func_08005974
	.thumb
	.thumb_func
	.type func_08005974, %function
func_08005974: @ 08005974
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r5, [sp, #0x00C]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r0, [r4, #0x04]
	cmp r0, r5
	bne _08005994
	ldr r0, [r4, #0x00]
	cmp r0, r3
	bne _08005994
	ldrh r0, [r4, #0x10]
	cmp r0, r1
	beq _0800599E
_08005994:
	str r5, [r4, #0x04]
	str r3, [r4, #0x00]
	adds r0, r4, #0x0
	bl func_080059A4
_0800599E:
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
