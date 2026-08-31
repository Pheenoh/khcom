.syntax unified
	.align 2, 0
	.global DrawSprite
	.thumb
	.thumb_func
	.type DrawSprite, %function
DrawSprite: @ 080023E0
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	mov r12, r2
	adds r5, r3, #0x0
	ldr r6, [sp, #0x028]
	ldr r2, [sp, #0x02C]
	ldr r3, [sp, #0x030]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r0, _08002420 @ =0x030074C8
	ldr r0, [r0, #0x00]
	ldr r7, _08002424 @ =0x000028A8
	adds r0, r0, r7
	ldrh r0, [r0, #0x00]
	cmp r0, #0x7F
	bhi _0800247C
	cmp r5, #0x00
	beq _0800247C
	ldr r0, [r5, #0x28]
	cmp r0, #0x01
	beq _08002444
	cmp r0, #0x01
	bcc _08002428
	cmp r0, #0x02
	beq _08002460
	b _0800247C
_08002420: .4byte 0x030074C8
_08002424: .4byte 0x000028A8
_08002428:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r4, [sp, #0x024]
	str r4, [sp, #0x000]
	str r6, [sp, #0x004]
	str r2, [sp, #0x008]
	str r3, [sp, #0x00C]
	mov r2, r12
	adds r3, r5, #0x0
	bl func_08002060
	b _08002476
_08002444:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r7, [sp, #0x024]
	str r7, [sp, #0x000]
	str r6, [sp, #0x004]
	str r2, [sp, #0x008]
	str r3, [sp, #0x00C]
	mov r2, r12
	adds r3, r5, #0x0
	bl func_0800216C
	b _08002476
_08002460:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	str r6, [sp, #0x000]
	str r2, [sp, #0x004]
	str r3, [sp, #0x008]
	adds r2, r5, #0x0
	ldr r3, [sp, #0x024]
	bl func_080022D4
_08002476:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0800247E
_0800247C:
	movs r0, #0x00
_0800247E:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
