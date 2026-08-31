.syntax unified
	.align 2, 0
	.global func_080E524C
	.thumb
	.thumb_func
	.type func_080E524C, %function
func_080E524C: @ 080E524C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	mov r10, r0
	str r1, [sp, #0x000]
	ldr r0, _080E52E0 @ =0x02034F2E
	ldr r1, _080E52E4 @ =0x02034F2C
	ldrh r0, [r0, #0x00]
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	bl GetRandom
	ldr r1, _080E52E8 @ =0x02034F28
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1, #0x00]
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, r9
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0x00
	mov r8, r0
	cmp r8, r9
	bge _080E5326
_080E529A:
	movs r7, #0x00
	ldr r0, _080E52E8 @ =0x02034F28
	ldrh r0, [r0, #0x00]
	cmp r7, r0
	bge _080E530C
_080E52A4:
	ldr r0, _080E52E4 @ =0x02034F2C
	ldrh r1, [r0, #0x00]
	adds r1, r6, r1
	lsls r1, r1, #0x10
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	lsrs r4, r1, #0x10
	asrs r1, r1, #0x10
	bl func_080E08BC
	ldr r0, [r0, #0x00]
	ldr r1, _080E52EC @ =0x00FF0340
	ands r0, r1
	cmp r0, #0x00
	bne _080E52F0
	lsls r0, r5, #0x0D
	movs r1, #0x80
	lsls r1, r1, #0x05
	adds r0, r0, r1
	mov r2, r10
	str r0, [r2, #0x00]
	lsls r0, r4, #0x0C
	movs r1, #0x80
	lsls r1, r1, #0x04
	adds r0, r0, r1
	ldr r2, [sp, #0x000]
	str r0, [r2, #0x00]
	movs r0, #0x01
	b _080E533C
	.byte 0x00, 0x00
_080E52E0: .4byte 0x02034F2E
_080E52E4: .4byte 0x02034F2C
_080E52E8: .4byte 0x02034F28
_080E52EC: .4byte 0x00FF0340
_080E52F0:
	adds r0, r5, #0x1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, _080E534C @ =0x02034F28
	ldrh r4, [r0, #0x00]
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r7, #0x01
	cmp r7, r4
	blt _080E52A4
_080E530C:
	adds r0, r6, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r6, #0x0
	mov r1, r9
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0x01
	add r8, r0
	cmp r8, r9
	blt _080E529A
_080E5326:
	ldr r0, _080E5350 @ =0x02039BA0
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x18]
	mov r2, r10
	str r0, [r2, #0x00]
	ldr r0, [r1, #0x1C]
	ldr r1, [r1, #0x24]
	adds r0, r0, r1
	ldr r1, [sp, #0x000]
	str r0, [r1, #0x00]
	movs r0, #0x00
_080E533C:
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_080E534C: .4byte 0x02034F28
_080E5350: .4byte 0x02039BA0
.syntax divided
