.syntax unified
	.align 2, 0
	.global func_080051C4
	.thumb
	.thumb_func
	.type func_080051C4, %function
func_080051C4: @ 080051C4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r4, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldr r0, _0800523C @ =0x030074D4
	lsls r1, r4, #0x04
	ldr r0, [r0, #0x00]
	adds r5, r0, r1
	ldr r0, [r5, #0x04]
	cmp r0, #0x00
	beq _08005230
	movs r0, #0x00
	mov r8, r0
	movs r2, #0x00
	strh r6, [r5, #0x0A]
	strh r7, [r5, #0x0C]
	ldr r1, _08005240 @ =0x09ECEB30
	lsls r0, r4, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x00]
	movs r3, #0xF8
	lsls r3, r3, #0x05
	ands r3, r0
	lsls r3, r3, #0x03
	movs r0, #0xC0
	lsls r0, r0, #0x13
	adds r3, r3, r0
	str r2, [sp, #0x000]
	str r2, [sp, #0x004]
	movs r0, #0x1F
	str r0, [sp, #0x008]
	movs r0, #0x15
	str r0, [sp, #0x00C]
	adds r0, r6, #0x0
	adds r1, r7, #0x0
	adds r2, r5, #0x0
	bl func_08004C20
	movs r0, #0x07
	adds r1, r6, #0x0
	ands r1, r0
	adds r2, r7, #0x0
	ands r2, r0
	adds r0, r4, #0x0
	bl SetBgScroll
	mov r0, r8
	strb r0, [r5, #0x00]
_08005230:
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0800523C: .4byte 0x030074D4
_08005240: .4byte 0x09ECEB30
.syntax divided
