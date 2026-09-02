.syntax unified
	.align 2, 0
	.global func_0808FA8C
	.thumb
	.thumb_func
	.type func_0808FA8C, %function
func_0808FA8C: @ 0808FA8C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	mov r8, r0
	ldr r0, _0808FDFC @ =0x00000898
	add r0, r8
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x05
	bl EwramAlloc
	ldr r1, _0808FE00 @ =0x000004D4
	add r1, r8
	str r0, [r1, #0x00]
	movs r0, #0x00
	mov r9, r0
	movs r6, #0x00
	movs r1, #0x9B
	lsls r1, r1, #0x03
	add r1, r8
	mov r10, r1
	ldr r2, _0808FE00 @ =0x000004D4
	add r2, r8
	str r2, [sp, #0x000]
_0808FAC0:
	mov r3, r10
	ldr r0, [r3, #0x00]
	mov r7, r9
	lsls r1, r7, #0x05
	adds r2, r1, r0
	ldrh r0, [r2, #0x16]
	adds r5, r1, #0x0
	cmp r0, #0x00
	beq _0808FB44
	ldr r0, [sp, #0x000]
	ldr r1, [r0, #0x00]
	lsls r4, r6, #0x05
	adds r1, r4, r1
	adds r0, r2, #0x0
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r2, r3}
	stm r1!, {r2, r3}
	mov r7, r10
	ldr r0, [r7, #0x00]
	adds r0, r5, r0
	ldrh r0, [r0, #0x18]
	lsls r0, r0, #0x01
	bl EwramAlloc
	ldr r2, [sp, #0x000]
	ldr r1, [r2, #0x00]
	adds r1, r4, r1
	str r0, [r1, #0x1C]
	movs r3, #0x00
	ldr r0, [r7, #0x00]
	adds r0, r5, r0
	adds r7, r6, #0x1
	ldrh r0, [r0, #0x18]
	cmp r3, r0
	bcs _0808FB40
	ldr r0, _0808FE00 @ =0x000004D4
	add r0, r8
	mov r12, r0
	movs r6, #0x9B
	lsls r6, r6, #0x03
	add r6, r8
_0808FB18:
	mov r1, r12
	ldr r0, [r1, #0x00]
	adds r0, r4, r0
	ldr r2, [r0, #0x1C]
	lsls r1, r3, #0x01
	adds r2, r1, r2
	ldr r0, [r6, #0x00]
	adds r0, r5, r0
	ldr r0, [r0, #0x1C]
	adds r1, r1, r0
	ldrh r0, [r1, #0x00]
	strh r0, [r2, #0x00]
	adds r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, [r6, #0x00]
	adds r0, r5, r0
	ldrh r0, [r0, #0x18]
	cmp r3, r0
	bcc _0808FB18
_0808FB40:
	lsls r0, r7, #0x10
	lsrs r6, r0, #0x10
_0808FB44:
	mov r0, r9
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	cmp r0, #0x10
	bls _0808FAC0
	movs r2, #0x8F
	mov r9, r2
	movs r3, #0x9B
	lsls r3, r3, #0x03
	add r3, r8
	mov r10, r3
	ldr r7, _0808FE00 @ =0x000004D4
	add r7, r8
	str r7, [sp, #0x004]
_0808FB64:
	mov r1, r10
	ldr r0, [r1, #0x00]
	mov r2, r9
	lsls r1, r2, #0x05
	adds r2, r1, r0
	ldrh r0, [r2, #0x16]
	adds r5, r1, #0x0
	cmp r0, #0x00
	beq _0808FBEA
	ldr r3, [sp, #0x004]
	ldr r1, [r3, #0x00]
	lsls r4, r6, #0x05
	adds r1, r4, r1
	adds r0, r2, #0x0
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r2, r7}
	stm r1!, {r2, r7}
	mov r3, r10
	ldr r0, [r3, #0x00]
	adds r0, r5, r0
	ldrh r0, [r0, #0x18]
	lsls r0, r0, #0x01
	bl EwramAlloc
	ldr r7, [sp, #0x004]
	ldr r1, [r7, #0x00]
	adds r1, r4, r1
	str r0, [r1, #0x1C]
	movs r3, #0x00
	mov r1, r10
	ldr r0, [r1, #0x00]
	adds r0, r5, r0
	adds r7, r6, #0x1
	ldrh r0, [r0, #0x18]
	cmp r3, r0
	bcs _0808FBE6
	ldr r2, _0808FE00 @ =0x000004D4
	add r2, r8
	mov r12, r2
	movs r6, #0x9B
	lsls r6, r6, #0x03
	add r6, r8
_0808FBBE:
	mov r1, r12
	ldr r0, [r1, #0x00]
	adds r0, r4, r0
	ldr r2, [r0, #0x1C]
	lsls r1, r3, #0x01
	adds r2, r1, r2
	ldr r0, [r6, #0x00]
	adds r0, r5, r0
	ldr r0, [r0, #0x1C]
	adds r1, r1, r0
	ldrh r0, [r1, #0x00]
	strh r0, [r2, #0x00]
	adds r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, [r6, #0x00]
	adds r0, r5, r0
	ldrh r0, [r0, #0x18]
	cmp r3, r0
	bcc _0808FBBE
_0808FBE6:
	lsls r0, r7, #0x10
	lsrs r6, r0, #0x10
_0808FBEA:
	mov r0, r9
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	cmp r0, #0x9F
	bls _0808FB64
	movs r2, #0x12
	mov r9, r2
	movs r3, #0x9B
	lsls r3, r3, #0x03
	add r3, r8
	mov r10, r3
	ldr r7, _0808FE00 @ =0x000004D4
	add r7, r8
	str r7, [sp, #0x008]
_0808FC0A:
	mov r1, r10
	ldr r0, [r1, #0x00]
	mov r2, r9
	lsls r1, r2, #0x05
	adds r2, r1, r0
	ldrh r0, [r2, #0x16]
	adds r5, r1, #0x0
	cmp r0, #0x00
	beq _0808FC90
	ldr r3, [sp, #0x008]
	ldr r1, [r3, #0x00]
	lsls r4, r6, #0x05
	adds r1, r4, r1
	adds r0, r2, #0x0
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r2, r7}
	stm r1!, {r2, r7}
	mov r3, r10
	ldr r0, [r3, #0x00]
	adds r0, r5, r0
	ldrh r0, [r0, #0x18]
	lsls r0, r0, #0x01
	bl EwramAlloc
	ldr r7, [sp, #0x008]
	ldr r1, [r7, #0x00]
	adds r1, r4, r1
	str r0, [r1, #0x1C]
	movs r3, #0x00
	mov r1, r10
	ldr r0, [r1, #0x00]
	adds r0, r5, r0
	adds r7, r6, #0x1
	ldrh r0, [r0, #0x18]
	cmp r3, r0
	bcs _0808FC8C
	ldr r2, _0808FE00 @ =0x000004D4
	add r2, r8
	mov r12, r2
	movs r6, #0x9B
	lsls r6, r6, #0x03
	add r6, r8
_0808FC64:
	mov r1, r12
	ldr r0, [r1, #0x00]
	adds r0, r4, r0
	ldr r2, [r0, #0x1C]
	lsls r1, r3, #0x01
	adds r2, r1, r2
	ldr r0, [r6, #0x00]
	adds r0, r5, r0
	ldr r0, [r0, #0x1C]
	adds r1, r1, r0
	ldrh r0, [r1, #0x00]
	strh r0, [r2, #0x00]
	adds r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, [r6, #0x00]
	adds r0, r5, r0
	ldrh r0, [r0, #0x18]
	cmp r3, r0
	bcc _0808FC64
_0808FC8C:
	lsls r0, r7, #0x10
	lsrs r6, r0, #0x10
_0808FC90:
	mov r0, r9
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	cmp r0, #0x1F
	bls _0808FC0A
	movs r2, #0xA1
	mov r9, r2
	movs r3, #0x9B
	lsls r3, r3, #0x03
	add r3, r8
	mov r10, r3
	ldr r7, _0808FE00 @ =0x000004D4
	add r7, r8
	str r7, [sp, #0x00C]
_0808FCB0:
	mov r1, r10
	ldr r0, [r1, #0x00]
	mov r2, r9
	lsls r1, r2, #0x05
	adds r2, r1, r0
	ldrh r0, [r2, #0x16]
	adds r5, r1, #0x0
	cmp r0, #0x00
	beq _0808FD36
	ldr r3, [sp, #0x00C]
	ldr r1, [r3, #0x00]
	lsls r4, r6, #0x05
	adds r1, r4, r1
	adds r0, r2, #0x0
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r2, r7}
	stm r1!, {r2, r7}
	mov r3, r10
	ldr r0, [r3, #0x00]
	adds r0, r5, r0
	ldrh r0, [r0, #0x18]
	lsls r0, r0, #0x01
	bl EwramAlloc
	ldr r7, [sp, #0x00C]
	ldr r1, [r7, #0x00]
	adds r1, r4, r1
	str r0, [r1, #0x1C]
	movs r3, #0x00
	mov r1, r10
	ldr r0, [r1, #0x00]
	adds r0, r5, r0
	adds r7, r6, #0x1
	ldrh r0, [r0, #0x18]
	cmp r3, r0
	bcs _0808FD32
	ldr r2, _0808FE00 @ =0x000004D4
	add r2, r8
	mov r12, r2
	movs r6, #0x9B
	lsls r6, r6, #0x03
	add r6, r8
_0808FD0A:
	mov r1, r12
	ldr r0, [r1, #0x00]
	adds r0, r4, r0
	ldr r2, [r0, #0x1C]
	lsls r1, r3, #0x01
	adds r2, r1, r2
	ldr r0, [r6, #0x00]
	adds r0, r5, r0
	ldr r0, [r0, #0x1C]
	adds r1, r1, r0
	ldrh r0, [r1, #0x00]
	strh r0, [r2, #0x00]
	adds r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, [r6, #0x00]
	adds r0, r5, r0
	ldrh r0, [r0, #0x18]
	cmp r3, r0
	bcc _0808FD0A
_0808FD32:
	lsls r0, r7, #0x10
	lsrs r6, r0, #0x10
_0808FD36:
	mov r0, r9
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	cmp r0, #0xAE
	bls _0808FCB0
	movs r2, #0x20
	mov r9, r2
	movs r3, #0x9B
	lsls r3, r3, #0x03
	add r3, r8
	mov r10, r3
	ldr r7, _0808FE00 @ =0x000004D4
	add r7, r8
	str r7, [sp, #0x010]
_0808FD56:
	mov r1, r10
	ldr r0, [r1, #0x00]
	mov r2, r9
	lsls r1, r2, #0x05
	adds r2, r1, r0
	ldrh r0, [r2, #0x16]
	adds r5, r1, #0x0
	movs r3, #0x01
	add r9, r3
	cmp r0, #0x00
	beq _0808FDDE
	ldr r7, [sp, #0x010]
	ldr r1, [r7, #0x00]
	lsls r4, r6, #0x05
	adds r1, r4, r1
	adds r0, r2, #0x0
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r2, r3}
	stm r1!, {r2, r3}
	mov r7, r10
	ldr r0, [r7, #0x00]
	adds r0, r5, r0
	ldrh r0, [r0, #0x18]
	lsls r0, r0, #0x01
	bl EwramAlloc
	ldr r2, [sp, #0x010]
	ldr r1, [r2, #0x00]
	adds r1, r4, r1
	str r0, [r1, #0x1C]
	movs r3, #0x00
	ldr r0, [r7, #0x00]
	adds r0, r5, r0
	adds r7, r6, #0x1
	ldrh r0, [r0, #0x18]
	cmp r3, r0
	bcs _0808FDDA
	ldr r0, _0808FE00 @ =0x000004D4
	add r0, r8
	mov r12, r0
	movs r6, #0x9B
	lsls r6, r6, #0x03
	add r6, r8
_0808FDB2:
	mov r1, r12
	ldr r0, [r1, #0x00]
	adds r0, r4, r0
	ldr r2, [r0, #0x1C]
	lsls r1, r3, #0x01
	adds r2, r1, r2
	ldr r0, [r6, #0x00]
	adds r0, r5, r0
	ldr r0, [r0, #0x1C]
	adds r1, r1, r0
	ldrh r0, [r1, #0x00]
	strh r0, [r2, #0x00]
	adds r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, [r6, #0x00]
	adds r0, r5, r0
	ldrh r0, [r0, #0x18]
	cmp r3, r0
	bcc _0808FDB2
_0808FDDA:
	lsls r0, r7, #0x10
	lsrs r6, r0, #0x10
_0808FDDE:
	mov r2, r9
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	cmp r0, #0x8E
	bls _0808FD56
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0808FDFC: .4byte 0x00000898
_0808FE00: .4byte 0x000004D4
.syntax divided
