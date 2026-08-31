.syntax unified
	.align 2, 0
	.global task_poo_piglet_2
	.thumb
	.thumb_func
	.type task_poo_piglet_2, %function
task_poo_piglet_2: @ 080CDBB4
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x010
	adds r5, r0, #0x0
	ldr r0, [r5, #0x28]
	asrs r0, r0, #0x08
	ldr r1, _080CDC1C @ =0x0203C40C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, [r5, #0x2C]
	asrs r1, r1, #0x08
	ldr r2, _080CDC20 @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r2, r0, #0x10
	mov r9, r2
	asrs r0, r0, #0x10
	lsrs r6, r1, #0x10
	mov r8, r6
	asrs r1, r1, #0x10
	movs r2, #0x08
	str r2, [sp, #0x000]
	str r2, [sp, #0x004]
	movs r2, #0x18
	movs r3, #0x08
	bl func_080035CC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CDC24
	ldr r0, [r5, #0x04]
	cmp r0, #0x00
	beq _080CDCCE
	bl ReleaseObjPalette
	adds r0, r5, #0x0
	adds r0, #0x38
	bl func_08012304
	adds r0, r5, #0x0
	adds r0, #0xB4
	ldrh r0, [r0, #0x00]
	movs r1, #0x00
	bl func_080D2E70
	movs r0, #0x00
	str r0, [r5, #0x04]
	b _080CDCCE
_080CDC1C: .4byte 0x0203C40C
_080CDC20: .4byte 0x0203C3F8
_080CDC24:
	adds r4, r5, #0x0
	adds r4, #0x94
	adds r0, r4, #0x0
	bl TaskPoolUpdate
	ldr r0, [r5, #0x04]
	adds r6, r5, #0x0
	adds r6, #0x38
	adds r7, r4, #0x0
	cmp r0, #0x00
	bne _080CDC7C
	ldr r0, _080CDC60 @ =0x09849C18
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x04]
	movs r0, #0x00
	bl func_080D2D50
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CDC64
	adds r0, r6, #0x0
	movs r1, #0x0A
	movs r2, #0x04
	movs r3, #0x10
	bl func_080122AC
	b _080CDC70
	.byte 0x00, 0x00
_080CDC60: .4byte 0x09849C18
_080CDC64:
	adds r0, r6, #0x0
	movs r1, #0x0A
	movs r2, #0x10
	movs r3, #0x10
	bl func_080122AC
_080CDC70:
	adds r0, r5, #0x0
	adds r0, #0xB4
	ldrh r0, [r0, #0x00]
	movs r1, #0x01
	bl func_080D2E70
_080CDC7C:
	ldr r1, [r5, #0x28]
	ldr r2, [r5, #0x2C]
	ldr r3, [r5, #0x30]
	adds r0, r6, #0x0
	bl func_08012324
	adds r0, r5, #0x0
	adds r0, #0x24
	ldrb r0, [r0, #0x00]
	movs r6, #0x80
	lsls r6, r6, #0x04
	cmp r0, #0x00
	beq _080CDC98
	adds r6, #0x01
_080CDC98:
	mov r1, r9
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	mov r2, r8
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x00]
	ldr r4, [r5, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r6, [sp, #0x008]
	ldr r5, [r5, #0x2C]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	ldr r6, _080CDCDC @ =0xFFFFEFFC
	adds r4, r6, #0x0
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
	adds r0, r7, #0x0
	bl TaskPoolDraw
_080CDCCE:
	add sp, #0x010
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080CDCDC: .4byte 0xFFFFEFFC
.syntax divided
