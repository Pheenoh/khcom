.syntax unified
	.align 2, 0
	.global func_08093E34
	.thumb
	.thumb_func
	.type func_08093E34, %function
func_08093E34: @ 08093E34
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	mov r9, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r8, r6
	movs r7, #0x00
	adds r0, r6, #0x0
	adds r0, #0x0A
	cmp r6, r0
	bge _08093EE4
	ldr r0, _08093E9C @ =0x09EE4BE0
	mov r10, r0
_08093E54:
	ldr r0, _08093EA0 @ =0x0203A8C0
	adds r0, r6, r0
	ldrb r4, [r0, #0x00]
	cmp r4, #0x00
	beq _08093EA8
	adds r5, r4, #0x0
	cmp r5, #0x09
	bls _08093E68
	movs r5, #0x09
	strb r5, [r0, #0x00]
_08093E68:
	adds r4, r5, #0x1
	lsls r4, r4, #0x05
	ldr r0, _08093EA4 @ =0x09507F38
	adds r4, r4, r0
	movs r0, #0x01
	bl GetBgCharBase
	adds r1, r0, #0x0
	mov r2, r8
	subs r0, r6, r2
	lsls r0, r0, #0x01
	add r0, r10
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x05
	adds r1, r1, r0
	adds r0, r4, #0x0
	movs r2, #0x20
	bl RequestDma3Copy
	movs r0, #0xB4
	lsls r0, r0, #0x02
	add r0, r9
	adds r0, r0, r7
	strb r5, [r0, #0x00]
	b _08093ED0
	.byte 0x00, 0x00
_08093E9C: .4byte 0x09EE4BE0
_08093EA0: .4byte 0x0203A8C0
_08093EA4: .4byte 0x09507F38
_08093EA8:
	movs r0, #0x01
	bl GetBgCharBase
	adds r1, r0, #0x0
	mov r2, r8
	subs r0, r6, r2
	lsls r0, r0, #0x01
	add r0, r10
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x05
	adds r1, r1, r0
	ldr r0, _08093EFC @ =0x09507F58
	movs r2, #0x20
	bl RequestDma3Copy
	movs r0, #0xB4
	lsls r0, r0, #0x02
	add r0, r9
	adds r0, r0, r7
	strb r4, [r0, #0x00]
_08093ED0:
	adds r0, r6, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r7, #0x1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov r0, r8
	adds r0, #0x0A
	cmp r6, r0
	blt _08093E54
_08093EE4:
	movs r6, #0x00
	movs r1, #0xB4
	lsls r1, r1, #0x02
	add r1, r9
_08093EEC:
	adds r0, r1, r6
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08093F00
	lsls r0, r6, #0x18
	asrs r0, r0, #0x18
	b _08093F0E
	.byte 0x00, 0x00
_08093EFC: .4byte 0x09507F58
_08093F00:
	adds r0, r6, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0x09
	bls _08093EEC
	movs r0, #0x01
	negs r0, r0
_08093F0E:
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
