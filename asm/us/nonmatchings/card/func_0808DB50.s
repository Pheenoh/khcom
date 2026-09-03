.syntax unified
	.align 2, 0
	.global func_0808DB50
	.thumb
	.thumb_func
	.type func_0808DB50, %function
func_0808DB50: @ 0808DB50
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0x0
	ldr r0, _0808DB74 @ =0x0000FFFF
	mov r9, r0
	movs r1, #0xFE
	lsls r1, r1, #0x03
	adds r0, r5, r1
	bl ListPoolFirst
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _0808DBAE
	ldr r3, _0808DB78 @ =0x00000886
	adds r0, r5, r3
	b _0808DB8E
_0808DB74: .4byte 0x0000FFFF
_0808DB78: .4byte 0x00000886
_0808DB7C:
	adds r0, r2, #0x0
	adds r0, #0x2C
	bl ListPoolNext
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _0808DBAE
	ldr r1, _0808DCC8 @ =0x00000886
	adds r0, r5, r1
_0808DB8E:
	movs r3, #0x24
	ldsh r1, [r2, r3]
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r1, r0
	bne _0808DB7C
	ldr r1, _0808DCCC @ =0x00000884
	adds r0, r5, r1
	movs r3, #0x22
	ldsh r1, [r2, r3]
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r1, r0
	bne _0808DB7C
	ldrh r2, [r2, #0x20]
	mov r9, r2
_0808DBAE:
	adds r0, r5, #0x0
	bl func_0808DB04
	ldr r0, _0808DCD0 @ =0x0000FFFF
	cmp r9, r0
	bne _0808DBBC
	b _0808DD0C
_0808DBBC:
	movs r0, #0x80
	lsls r0, r0, #0x08
	mov r1, r9
	ands r0, r1
	cmp r0, #0x00
	beq _0808DC02
	movs r0, #0xA0
	lsls r0, r0, #0x02
	movs r1, #0x00
	bl AllocObjTiles
	str r0, [r5, #0x28]
	ldr r1, _0808DCD4 @ =0x0908B1B4
	bl func_08002A10
	movs r2, #0x83
	lsls r2, r2, #0x04
	adds r4, r5, r2
	ldr r1, _0808DCD8 @ =0x09EEA164
	ldr r2, _0808DCDC @ =0x09EEA148
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	movs r3, #0x9F
	lsls r3, r3, #0x03
	adds r1, r5, r3
	str r0, [r1, #0x00]
_0808DC02:
	ldr r0, _0808DCE0 @ =0x00000FFF
	mov r1, r9
	ands r1, r0
	mov r8, r1
	movs r0, #0x34
	mov r1, r8
	muls r1, r0
	ldr r0, _0808DCE4 @ =0x08F70AB0
	adds r6, r1, r0
	ldr r4, _0808DCE8 @ =0x08F709B0
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
	str r0, [r5, #0x1C]
	ldr r0, [r6, #0x04]
	movs r1, #0x80
	lsls r1, r1, #0x02
	bl LoadObjTiles
	str r0, [r5, #0x20]
	ldr r0, [r6, #0x08]
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x34]
	ldr r0, _0808DCEC @ =0x09611AB8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x30]
	ldr r3, _0808DCF0 @ =0x000004DC
	adds r2, r5, r3
	ldrb r1, [r7, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	movs r0, #0x9C
	lsls r0, r0, #0x03
	adds r1, r5, r0
	ldr r0, [r6, #0x00]
	str r0, [r1, #0x00]
	ldr r0, _0808DCF4 @ =0x000001C1
	cmp r8, r0
	bhi _0808DC96
	ldr r0, _0808DCF8 @ =0x0905EAE8
	movs r1, #0xF0
	lsls r1, r1, #0x01
	bl LoadObjTiles
	str r0, [r5, #0x24]
	ldr r1, _0808DCFC @ =0x000004E4
	adds r2, r5, r1
	ldr r1, _0808DD00 @ =0x09EE981C
	adds r0, r6, #0x0
	adds r0, #0x20
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
_0808DC96:
	mov r0, r9
	bl func_080609AC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl func_0808DE28
	ldr r1, _0808DD04 @ =0x05000160
	ldrb r0, [r7, #0x00]
	lsls r0, r0, #0x05
	ldr r2, _0808DD08 @ =0x09614318
	adds r0, r0, r2
	movs r2, #0x20
	bl LoadPalette
	adds r0, r5, #0x0
	mov r1, r8
	bl func_0808D73C
	adds r0, r5, #0x0
	mov r1, r8
	bl func_0808D7EC
	b _0808DD12
	.byte 0x00, 0x00
_0808DCC8: .4byte 0x00000886
_0808DCCC: .4byte 0x00000884
_0808DCD0: .4byte 0x0000FFFF
_0808DCD4: .4byte 0x0908B1B4
_0808DCD8: .4byte 0x09EEA164
_0808DCDC: .4byte 0x09EEA148
_0808DCE0: .4byte 0x00000FFF
_0808DCE4: .4byte 0x08F70AB0
_0808DCE8: .4byte 0x08F709B0
_0808DCEC: .4byte 0x09611AB8
_0808DCF0: .4byte 0x000004DC
_0808DCF4: .4byte 0x000001C1
_0808DCF8: .4byte 0x0905EAE8
_0808DCFC: .4byte 0x000004E4
_0808DD00: .4byte 0x09EE981C
_0808DD04: .4byte 0x05000160
_0808DD08: .4byte 0x09614318
_0808DD0C:
	movs r0, #0x00
	bl func_0808DE28
_0808DD12:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
