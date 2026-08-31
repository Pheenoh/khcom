.syntax unified
	.align 2, 0
	.global func_080A6FAC
	.thumb
	.thumb_func
	.type func_080A6FAC, %function
func_080A6FAC: @ 080A6FAC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0x0
	ldr r6, _080A6FCC @ =0x0000FFFF
	ldr r1, _080A6FD0 @ =0x00000434
	adds r0, r5, r1
	bl func_08000C8C
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _080A700A
	ldr r3, _080A6FD4 @ =0x000004CA
	adds r0, r5, r3
	b _080A6FEA
	.byte 0x00, 0x00
_080A6FCC: .4byte 0x0000FFFF
_080A6FD0: .4byte 0x00000434
_080A6FD4: .4byte 0x000004CA
_080A6FD8:
	adds r0, r2, #0x0
	adds r0, #0x2C
	bl func_08000CD4
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _080A700A
	ldr r1, _080A7128 @ =0x000004CA
	adds r0, r5, r1
_080A6FEA:
	movs r3, #0x24
	ldsh r1, [r2, r3]
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r1, r0
	bne _080A6FD8
	movs r1, #0x99
	lsls r1, r1, #0x03
	adds r0, r5, r1
	movs r3, #0x22
	ldsh r1, [r2, r3]
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r1, r0
	bne _080A6FD8
	ldrh r6, [r2, #0x20]
_080A700A:
	adds r0, r5, #0x0
	bl func_080A6F60
	ldr r0, _080A712C @ =0x0000FFFF
	cmp r6, r0
	bne _080A7018
	b _080A7164
_080A7018:
	movs r0, #0x80
	lsls r0, r0, #0x08
	ands r0, r6
	cmp r0, #0x00
	beq _080A705A
	movs r0, #0xA0
	lsls r0, r0, #0x02
	movs r1, #0x00
	bl AllocObjTiles
	str r0, [r5, #0x24]
	ldr r1, _080A7130 @ =0x0908B1B4
	bl func_08002A10
	ldr r0, _080A7134 @ =0x00000474
	adds r4, r5, r0
	ldr r1, _080A7138 @ =0x09EEA164
	ldr r2, _080A713C @ =0x09EEA148
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	movs r2, #0x81
	lsls r2, r2, #0x03
	adds r1, r5, r2
	str r0, [r1, #0x00]
_080A705A:
	ldr r3, _080A7140 @ =0x00000FFF
	mov r8, r3
	mov r0, r8
	ands r0, r6
	mov r8, r0
	movs r0, #0x34
	mov r1, r8
	muls r1, r0
	ldr r0, _080A7144 @ =0x08F70AB0
	adds r6, r1, r0
	ldr r4, _080A7148 @ =0x08F709B0
	adds r7, r6, #0x0
	adds r7, #0x2A
	ldrb r1, [r7, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r1, r4, #0x0
	adds r1, #0x0C
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	movs r1, #0xC0
	lsls r1, r1, #0x02
	bl LoadObjTiles
	str r0, [r5, #0x18]
	ldr r0, [r6, #0x04]
	movs r1, #0x80
	lsls r1, r1, #0x02
	bl LoadObjTiles
	str r0, [r5, #0x1C]
	ldr r0, [r6, #0x08]
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x2C]
	ldr r0, _080A714C @ =0x09611AB8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x28]
	movs r1, #0xFB
	lsls r1, r1, #0x02
	adds r2, r5, r1
	ldrb r1, [r7, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	movs r2, #0xFC
	lsls r2, r2, #0x02
	adds r1, r5, r2
	ldr r0, [r6, #0x00]
	str r0, [r1, #0x00]
	ldrb r0, [r7, #0x00]
	cmp r0, #0x03
	beq _080A70F4
	ldr r0, _080A7150 @ =0x0905EAE8
	movs r1, #0xF0
	lsls r1, r1, #0x01
	bl LoadObjTiles
	str r0, [r5, #0x20]
	movs r3, #0xFD
	lsls r3, r3, #0x02
	adds r2, r5, r3
	ldr r1, _080A7154 @ =0x09EE981C
	adds r0, r6, #0x0
	adds r0, #0x20
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
_080A70F4:
	ldrh r0, [r6, #0x2C]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl func_080A7180
	ldr r1, _080A7158 @ =0x05000160
	ldrb r0, [r7, #0x00]
	lsls r0, r0, #0x05
	ldr r2, _080A715C @ =0x09614318
	adds r0, r0, r2
	movs r2, #0x20
	bl LoadPalette
	adds r0, r5, #0x0
	mov r1, r8
	bl func_080A6EB4
	mov r1, r8
	adds r0, r5, #0x0
	bl func_080A5C60
	ldr r0, _080A7160 @ =0x0000050B
	adds r1, r5, r0
	movs r0, #0x01
	b _080A7170
	.byte 0x00, 0x00
_080A7128: .4byte 0x000004CA
_080A712C: .4byte 0x0000FFFF
_080A7130: .4byte 0x0908B1B4
_080A7134: .4byte 0x00000474
_080A7138: .4byte 0x09EEA164
_080A713C: .4byte 0x09EEA148
_080A7140: .4byte 0x00000FFF
_080A7144: .4byte 0x08F70AB0
_080A7148: .4byte 0x08F709B0
_080A714C: .4byte 0x09611AB8
_080A7150: .4byte 0x0905EAE8
_080A7154: .4byte 0x09EE981C
_080A7158: .4byte 0x05000160
_080A715C: .4byte 0x09614318
_080A7160: .4byte 0x0000050B
_080A7164:
	movs r0, #0x00
	bl func_080A7180
	ldr r2, _080A717C @ =0x0000050B
	adds r1, r5, r2
	movs r0, #0x00
_080A7170:
	strb r0, [r1, #0x00]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080A717C: .4byte 0x0000050B
.syntax divided
