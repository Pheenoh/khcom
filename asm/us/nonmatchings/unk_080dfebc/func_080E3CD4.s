.syntax unified
	.align 2, 0
	.global func_080E3CD4
	.thumb
	.thumb_func
	.type func_080E3CD4, %function
func_080E3CD4: @ 080E3CD4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	mov r9, r0
	mov r10, r1
	str r2, [sp, #0x000]
	str r3, [sp, #0x004]
	ldr r1, [sp, #0x030]
	ldr r0, [sp, #0x034]
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	lsls r1, r1, #0x10
	asrs r4, r1, #0x10
	subs r0, r6, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r1, r6, r4
	bl __modsi3
	adds r5, r4, r0
	movs r7, #0x00
	cmp r7, r8
	bge _080E3D6E
	str r4, [sp, #0x008]
	str r6, [sp, #0x00C]
_080E3D16:
	ldr r0, _080E3D4C @ =0x02034F2A
	ldrh r0, [r0, #0x00]
	subs r4, r0, #0x1
	cmp r4, #0x00
	blt _080E3D5A
	lsls r6, r5, #0x10
_080E3D22:
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	asrs r0, r6, #0x10
	bl func_080E08BC
	ldrb r1, [r0, #0x02]
	cmp r1, r9
	bne _080E3D50
	mov r1, r10
	strh r5, [r1, #0x00]
	ldr r1, [sp, #0x000]
	strh r4, [r1, #0x00]
	ldr r0, [r0, #0x08]
	asrs r0, r0, #0x08
	cmp r0, #0x00
	bge _080E3D44
	adds r0, #0x0F
_080E3D44:
	asrs r0, r0, #0x04
	ldr r1, [sp, #0x004]
	strh r0, [r1, #0x00]
	b _080E3D6E
_080E3D4C: .4byte 0x02034F2A
_080E3D50:
	cmp r1, #0x0B
	bne _080E3D5A
	subs r4, #0x01
	cmp r4, #0x00
	bge _080E3D22
_080E3D5A:
	ldr r0, [sp, #0x00C]
	subs r0, #0x01
	ldr r1, [sp, #0x008]
	cmp r5, r1
	ble _080E3D66
	subs r0, r5, #0x1
_080E3D66:
	adds r5, r0, #0x0
	adds r7, #0x01
	cmp r7, r8
	blt _080E3D16
_080E3D6E:
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
