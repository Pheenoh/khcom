.syntax unified
	.align 2, 0
	.global func_08101654
	.thumb
	.thumb_func
	.type func_08101654, %function
func_08101654: @ 08101654
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	movs r3, #0x00
	ldr r0, _08101728 @ =0x09993118
	mov r9, r0
	movs r1, #0x34
	add r1, r9
	mov r10, r1
_0810166A:
	lsls r3, r3, #0x10
	asrs r2, r3, #0x0B
	add r2, r9
	ldr r0, _0810172C @ =0x02035884
	ldr r1, [r0, #0x00]
	asrs r1, r1, #0x08
	ldrh r0, [r2, #0x1C]
	subs r0, r0, r1
	movs r6, #0x00
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	ldr r0, _08101730 @ =0x02035880
	ldr r0, [r0, #0x00]
	negs r0, r0
	asrs r1, r0, #0x08
	adds r0, r1, #0x0
	adds r0, #0x18
	cmp r2, r0
	ble _08101696
	adds r0, #0x6A
	cmp r2, r0
	blt _08101698
_08101696:
	movs r6, #0x01
_08101698:
	ldr r0, _08101734 @ =0x02035820
	asrs r7, r3, #0x10
	lsls r4, r7, #0x02
	adds r0, r0, r4
	mov r8, r0
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _081016AC
	bl func_08002C10
_081016AC:
	ldr r0, _08101738 @ =0x02035818
	adds r4, r4, r0
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	beq _081016BA
	bl func_080028C0
_081016BA:
	lsls r5, r7, #0x05
	movs r0, #0x5C
	muls r0, r6
	adds r5, r5, r0
	mov r0, r9
	adds r0, #0x20
	adds r0, r5, r0
	ldr r0, [r0, #0x00]
	mov r1, r9
	adds r6, r5, r1
	ldrh r1, [r6, #0x24]
	bl func_08002A14
	mov r1, r8
	str r0, [r1, #0x00]
	mov r0, r9
	adds r0, #0x28
	adds r0, r5, r0
	ldr r0, [r0, #0x00]
	ldrh r1, [r6, #0x2C]
	bl func_080026A4
	str r0, [r4, #0x00]
	lsls r4, r7, #0x01
	adds r4, r4, r7
	lsls r4, r4, #0x03
	ldr r0, _0810173C @ =0x02035828
	adds r4, r4, r0
	mov r0, r9
	adds r0, #0x30
	adds r0, r5, r0
	ldr r1, [r0, #0x00]
	add r5, r10
	ldr r2, [r5, #0x00]
	adds r0, r4, #0x0
	bl func_08005968
	ldrh r1, [r6, #0x38]
	adds r0, r4, #0x0
	movs r2, #0x01
	bl func_080059A4
	adds r0, r7, #0x1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x01
	ble _0810166A
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08101728: .4byte 0x09993118
_0810172C: .4byte 0x02035884
_08101730: .4byte 0x02035880
_08101734: .4byte 0x02035820
_08101738: .4byte 0x02035818
_0810173C: .4byte 0x02035828
.syntax divided
