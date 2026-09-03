.syntax unified
	.align 2, 0
	.global func_0808D828
	.thumb
	.thumb_func
	.type func_0808D828, %function
func_0808D828: @ 0808D828
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0x0
	ldr r0, _0808D84C @ =0x0000FFFF
	mov r8, r0
	movs r1, #0xFE
	lsls r1, r1, #0x03
	adds r0, r5, r1
	bl ListPoolFirst
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _0808D886
	ldr r3, _0808D850 @ =0x00000886
	adds r0, r5, r3
	b _0808D866
_0808D84C: .4byte 0x0000FFFF
_0808D850: .4byte 0x00000886
_0808D854:
	adds r0, r2, #0x0
	adds r0, #0x2C
	bl ListPoolNext
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _0808D886
	ldr r1, _0808D974 @ =0x00000886
	adds r0, r5, r1
_0808D866:
	movs r3, #0x24
	ldsh r1, [r2, r3]
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r1, r0
	bne _0808D854
	ldr r1, _0808D978 @ =0x00000884
	adds r0, r5, r1
	movs r3, #0x22
	ldsh r1, [r2, r3]
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r1, r0
	bne _0808D854
	ldrh r2, [r2, #0x20]
	mov r8, r2
_0808D886:
	adds r0, r5, #0x0
	bl func_0808DB04
	ldr r0, _0808D97C @ =0x0000FFFF
	cmp r8, r0
	bne _0808D894
	b _0808DADC
_0808D894:
	movs r0, #0x80
	lsls r0, r0, #0x08
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	cmp r0, #0x00
	beq _0808D8E0
	movs r0, #0xA0
	lsls r0, r0, #0x02
	movs r1, #0x00
	bl AllocObjTiles
	str r0, [r5, #0x28]
	ldr r1, _0808D980 @ =0x0908B1B4
	bl func_08002A10
	movs r2, #0x83
	lsls r2, r2, #0x04
	adds r4, r5, r2
	ldr r1, _0808D984 @ =0x09EEA164
	ldr r2, _0808D988 @ =0x09EEA148
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
_0808D8E0:
	ldr r0, _0808D98C @ =0x00000FFF
	mov r1, r8
	ands r0, r1
	movs r1, #0x34
	muls r1, r0
	ldr r0, _0808D990 @ =0x08F70AB0
	adds r7, r1, r0
	ldr r4, _0808D994 @ =0x08F709B0
	adds r6, r7, #0x0
	adds r6, #0x2A
	ldrb r1, [r6, #0x00]
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
	ldr r0, [r7, #0x04]
	movs r1, #0x80
	lsls r1, r1, #0x02
	bl LoadObjTiles
	str r0, [r5, #0x20]
	ldr r0, [r7, #0x08]
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x34]
	ldr r0, _0808D998 @ =0x09611AB8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x30]
	ldr r3, _0808D99C @ =0x000004DC
	adds r2, r5, r3
	ldrb r1, [r6, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	movs r0, #0x9C
	lsls r0, r0, #0x03
	adds r1, r5, r0
	ldr r0, [r7, #0x00]
	str r0, [r1, #0x00]
	movs r6, #0x00
	ldr r1, _0808D9A0 @ =0x00000898
	adds r0, r5, r1
	ldrh r0, [r0, #0x00]
	cmp r6, r0
	bcs _0808D9BC
	mov r4, r9
	subs r3, #0x08
	adds r2, r5, r3
	adds r3, r0, #0x0
_0808D95E:
	cmp r4, #0x00
	beq _0808D9A4
	ldr r1, [r2, #0x00]
	lsls r0, r6, #0x05
	adds r0, r0, r1
	ldrh r1, [r0, #0x14]
	ldrh r0, [r7, #0x1C]
	adds r0, #0x8F
	cmp r1, r0
	beq _0808D9BC
	b _0808D9B2
_0808D974: .4byte 0x00000886
_0808D978: .4byte 0x00000884
_0808D97C: .4byte 0x0000FFFF
_0808D980: .4byte 0x0908B1B4
_0808D984: .4byte 0x09EEA164
_0808D988: .4byte 0x09EEA148
_0808D98C: .4byte 0x00000FFF
_0808D990: .4byte 0x08F70AB0
_0808D994: .4byte 0x08F709B0
_0808D998: .4byte 0x09611AB8
_0808D99C: .4byte 0x000004DC
_0808D9A0: .4byte 0x00000898
_0808D9A4:
	ldr r0, [r2, #0x00]
	lsls r1, r6, #0x05
	adds r1, r1, r0
	ldrh r0, [r1, #0x14]
	ldrh r1, [r7, #0x1C]
	cmp r0, r1
	beq _0808D9BC
_0808D9B2:
	adds r0, r6, #0x1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, r3
	bcc _0808D95E
_0808D9BC:
	movs r2, #0x88
	lsls r2, r2, #0x04
	adds r0, r5, r2
	strh r6, [r0, #0x00]
	ldr r1, _0808DA44 @ =0x05000160
	adds r0, r7, #0x0
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x05
	ldr r2, _0808DA48 @ =0x09614318
	adds r0, r0, r2
	movs r2, #0x20
	bl LoadPalette
	movs r4, #0x00
	lsls r6, r6, #0x05
_0808D9DC:
	ldr r3, _0808DA4C @ =0x000004D4
	adds r0, r5, r3
	ldr r0, [r0, #0x00]
	adds r0, r6, r0
	lsls r1, r4, #0x01
	adds r0, r0, r1
	ldrb r0, [r0, #0x00]
	adds r1, r4, #0x0
	bl func_0808DD20
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x09
	bls _0808D9DC
	ldr r4, _0808DA50 @ =0x00000FFF
	mov r0, r8
	ands r4, r0
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_0808D73C
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_0808D7EC
	ldr r1, _0808DA54 @ =0x000008B1
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	subs r0, #0x09
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x03
	bhi _0808DA70
	ldrh r0, [r7, #0x1C]
	cmp r0, #0x2E
	bls _0808DA5C
	ldr r1, _0808DA58 @ =0x09518AB8
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x02
	bl LoadBgMap
	mov r0, r8
	bl func_080609AC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl func_0808DE28
	b _0808DAF6
	.byte 0x00, 0x00
_0808DA44: .4byte 0x05000160
_0808DA48: .4byte 0x09614318
_0808DA4C: .4byte 0x000004D4
_0808DA50: .4byte 0x00000FFF
_0808DA54: .4byte 0x000008B1
_0808DA58: .4byte 0x09518AB8
_0808DA5C:
	ldr r1, _0808DA6C @ =0x095182B8
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x02
	bl LoadBgMap
	b _0808DAD0
	.byte 0x00, 0x00
_0808DA6C: .4byte 0x095182B8
_0808DA70:
	ldrh r0, [r7, #0x1C]
	cmp r0, #0x2E
	bls _0808DA9C
	movs r2, #0x8C
	lsls r2, r2, #0x04
	adds r0, r5, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0808DA8C
	ldr r1, _0808DA88 @ =0x09518AB8
	b _0808DAAA
	.byte 0x00, 0x00
_0808DA88: .4byte 0x09518AB8
_0808DA8C:
	cmp r0, #0x00
	blt _0808DAD0
	cmp r0, #0x02
	bgt _0808DAD0
	ldr r1, _0808DA98 @ =0x09518AB8
	b _0808DAC6
_0808DA98: .4byte 0x09518AB8
_0808DA9C:
	movs r3, #0x8C
	lsls r3, r3, #0x04
	adds r0, r5, r3
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0808DABC
	ldr r1, _0808DAB8 @ =0x095182B8
_0808DAAA:
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x01
	bl LoadBgMap
	b _0808DAD0
	.byte 0x00, 0x00
_0808DAB8: .4byte 0x095182B8
_0808DABC:
	cmp r0, #0x00
	blt _0808DAD0
	cmp r0, #0x02
	bgt _0808DAD0
	ldr r1, _0808DAD8 @ =0x095182B8
_0808DAC6:
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgMap
_0808DAD0:
	movs r0, #0x00
	bl func_0808DE28
	b _0808DAF6
_0808DAD8: .4byte 0x095182B8
_0808DADC:
	movs r4, #0x00
_0808DADE:
	movs r0, #0x00
	adds r1, r4, #0x0
	bl func_0808DD20
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x09
	bls _0808DADE
	movs r0, #0x00
	bl func_0808DE28
_0808DAF6:
	mov r0, r8
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
