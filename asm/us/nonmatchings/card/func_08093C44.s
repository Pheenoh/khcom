.syntax unified
	.align 2, 0
	.global func_08093C44
	.thumb
	.thumb_func
	.type func_08093C44, %function
func_08093C44: @ 08093C44
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r1, #0x0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r12, r0
	movs r2, #0x00
	ldr r0, _08093CD0 @ =0x0000029E
	adds r3, r6, r0
	ldr r4, _08093CD4 @ =0x09619098
_08093C5A:
	adds r1, r3, r2
	adds r0, r2, #0x0
	adds r0, #0x20
	adds r0, r0, r4
	ldrb r0, [r0, #0x00]
	strb r0, [r1, #0x00]
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x15
	bls _08093C5A
	movs r2, #0x16
	ldr r1, _08093CD0 @ =0x0000029E
	adds r3, r6, r1
	ldr r4, _08093CD8 @ =0x09618C58
_08093C78:
	adds r1, r3, r2
	adds r0, r2, #0x0
	adds r0, #0x40
	adds r0, r0, r4
	ldrb r0, [r0, #0x00]
	strb r0, [r1, #0x00]
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x1F
	bls _08093C78
	mov r2, r12
	movs r4, #0x02
	adds r0, r2, #0x0
	adds r0, #0x0A
	cmp r2, r0
	bge _08093D0A
	ldr r1, _08093CDC @ =0x09EE4C80
	lsls r0, r2, #0x02
	adds r0, r0, r2
	lsls r0, r0, #0x03
	adds r7, r0, r1
	ldr r0, _08093CD0 @ =0x0000029E
	adds r3, r6, r0
	ldr r1, _08093CE0 @ =0x0203A8C0
	mov r8, r1
	ldr r5, _08093CD8 @ =0x09618C58
_08093CAE:
	mov r1, r8
	adds r0, r2, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08093CF6
	ldrb r0, [r7, #0x1E]
	cmp r0, #0x04
	beq _08093CE4
	adds r1, r3, r4
	movs r0, #0xFF
	strb r0, [r1, #0x00]
	adds r0, r4, #0x1
	adds r0, r3, r0
	movs r1, #0x7F
	strb r1, [r0, #0x00]
	b _08093CF6
	.byte 0x00, 0x00
_08093CD0: .4byte 0x0000029E
_08093CD4: .4byte 0x09619098
_08093CD8: .4byte 0x09618C58
_08093CDC: .4byte 0x09EE4C80
_08093CE0: .4byte 0x0203A8C0
_08093CE4:
	adds r1, r3, r4
	adds r0, r4, r5
	ldrb r0, [r0, #0x00]
	strb r0, [r1, #0x00]
	adds r0, r4, #0x1
	adds r1, r3, r0
	adds r0, r0, r5
	ldrb r0, [r0, #0x00]
	strb r0, [r1, #0x00]
_08093CF6:
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r0, r4, #0x2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mov r0, r12
	adds r0, #0x0A
	cmp r2, r0
	blt _08093CAE
_08093D0A:
	ldr r1, _08093D20 @ =0x0000029E
	adds r0, r6, r1
	ldr r1, _08093D24 @ =0x050001C0
	movs r2, #0x20
	bl LoadPalette
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08093D20: .4byte 0x0000029E
_08093D24: .4byte 0x050001C0
.syntax divided
